#!/bin/bash

# Script to convert DEB package to IPA format
# This creates a mock IPA structure from the DEB contents

set -e

DEB_FILE="$1"
OUTPUT_DIR="${2:-.}"

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
    # For tweaks without visible dylib, create minimal structure
    APP_DIR="$PAYLOAD_DIR/ffz.app"
else
    APP_DIR="$PAYLOAD_DIR/ffz.app"
fi

mkdir -p "$APP_DIR/Frameworks"

# Copy dylib if found
if [ -n "$DYLIB" ]; then
    cp "$DYLIB" "$APP_DIR/Frameworks/" || true
fi

# Create minimal Info.plist
cat > "$APP_DIR/Info.plist" << 'EOF'
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleDevelopmentRegion</key>
    <string>en</string>
    <key>CFBundleExecutable</key>
    <string>ffz</string>
    <key>CFBundleIdentifier</key>
    <string>com.zexis.so</string>
    <key>CFBundleInfoDictionaryVersion</key>
    <string>6.0</string>
    <key>CFBundleName</key>
    <string>IMGuiMod</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleShortVersionString</key>
    <string>4.0</string>
    <key>CFBundleVersion</key>
    <string>1</string>
    <key>LSRequiresIPhoneOS</key>
    <true/>
    <key>MinimumOSVersion</key>
    <string>16.5</string>
    <key>UIDeviceFamily</key>
    <array>
        <integer>1</integer>
        <integer>2</integer>
    </array>
    <key>UIRequiredDeviceCapabilities</key>
    <array>
        <string>armv7</string>
        <string>arm64</string>
    </array>
</dict>
</plist>
EOF

echo "Creating IPA package..."
cd "$IPA_DIR"
zip -r "${OUTPUT_DIR}/ffz.ipa" .

echo "Cleaning up..."
rm -rf "$TEMP_DIR"

echo "✓ IPA created: ${OUTPUT_DIR}/ffz.ipa"
