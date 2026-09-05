#!/bin/bash

# Script to convert DEB package to IPA format
# Creates an IPA structure from the DEB contents (dylib in Frameworks + stub app).
#
# Configurable via environment variables (defaults = iPhone build):
#   APP_NAME      Base name of the .app and output IPA   (default: ffz)
#   BUNDLE_ID     CFBundleIdentifier                     (default: com.zexis.so)
#   APP_TITLE     CFBundleName                           (default: IMGuiMod)
#   APP_VERSION   CFBundleShortVersionString             (default: 4.0)
#   MIN_OS        MinimumOSVersion                       (default: 14.5)
#   DEVICE_FAMILY Space-separated UIDeviceFamily values  (default: "1 2", iPad-only: "2")
#   OUTPUT_IPA    Output IPA file name                   (default: ${APP_NAME}.ipa)
#
# Usage:
#   bash scripts/deb-to-ipa.sh <package.deb> [output_dir]
#
# iPad example:
#   APP_NAME=ffzipad BUNDLE_ID=com.zexis.so.ipad APP_TITLE="IMGuiMod (iPad)" \
#     DEVICE_FAMILY="2" OUTPUT_IPA=ffzipad-ipad.ipa \
#     bash scripts/deb-to-ipa.sh ipad/packages/*.deb .

set -e

DEB_FILE="$1"
OUTPUT_DIR="${2:-.}"

APP_NAME="${APP_NAME:-ffz}"
BUNDLE_ID="${BUNDLE_ID:-com.zexis.so}"
APP_TITLE="${APP_TITLE:-IMGuiMod}"
APP_VERSION="${APP_VERSION:-4.0}"
MIN_OS="${MIN_OS:-16.5}"
DEVICE_FAMILY="${DEVICE_FAMILY:-1 2}"
OUTPUT_IPA="${OUTPUT_IPA:-${APP_NAME}.ipa}"

if [ ! -f "$DEB_FILE" ]; then
    echo "Error: DEB file not found: $DEB_FILE"
    exit 1
fi

# Create temporary directories
TEMP_DIR=$(mktemp -d)
EXTRACT_DIR="$TEMP_DIR/extract"
IPA_DIR="$TEMP_DIR/ipa"
PAYLOAD_DIR="$IPA_DIR/Payload"

mkdir -p "$EXTRACT_DIR" "$PAYLOAD_DIR"

echo "Extracting DEB package..."
cd "$EXTRACT_DIR"
ar x "$DEB_FILE"
tar xf data.tar.xz || tar xf data.tar.gz || tar xf data.tar

echo "Creating IPA structure..."
# Find the library and create app structure
DYLIB=$(find "$EXTRACT_DIR" -name "*.dylib" -type f | head -1)

if [ -z "$DYLIB" ]; then
    echo "Warning: No dylib found in package"
fi

APP_DIR="$PAYLOAD_DIR/${APP_NAME}.app"
mkdir -p "$APP_DIR/Frameworks"

# Copy dylib if found
if [ -n "$DYLIB" ]; then
    cp "$DYLIB" "$APP_DIR/Frameworks/" || true
fi

# Build UIDeviceFamily entries
DEVICE_FAMILY_ENTRIES=""
for f in $DEVICE_FAMILY; do
    DEVICE_FAMILY_ENTRIES="${DEVICE_FAMILY_ENTRIES}        <integer>${f}</integer>
"
done

# Create minimal Info.plist
cat > "$APP_DIR/Info.plist" << EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleDevelopmentRegion</key>
    <string>en</string>
    <key>CFBundleExecutable</key>
    <string>${APP_NAME}</string>
    <key>CFBundleIdentifier</key>
    <string>${BUNDLE_ID}</string>
    <key>CFBundleInfoDictionaryVersion</key>
    <string>6.0</string>
    <key>CFBundleName</key>
    <string>${APP_TITLE}</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleShortVersionString</key>
    <string>${APP_VERSION}</string>
    <key>CFBundleVersion</key>
    <string>1</string>
    <key>LSRequiresIPhoneOS</key>
    <true/>
    <key>MinimumOSVersion</key>
    <string>${MIN_OS}</string>
    <key>UIDeviceFamily</key>
    <array>
${DEVICE_FAMILY_ENTRIES}    </array>
    <key>UIRequiredDeviceCapabilities</key>
    <array>
        <string>arm64</string>
    </array>
</dict>
</plist>
EOF

echo "Creating IPA package..."
cd "$IPA_DIR"
zip -r "${OUTPUT_DIR}/${OUTPUT_IPA}" .

echo "Cleaning up..."
rm -rf "$TEMP_DIR"

echo "IPA created: ${OUTPUT_DIR}/${OUTPUT_IPA}"
