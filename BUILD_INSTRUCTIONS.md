# Build Instructions - GitHub Actions

## วิธีการ Build IPA ผ่าน GitHub Actions

### ขั้นตอน:

1. **Push โปรเจกต์ขึ้น GitHub**
   ```bash
   git add .
   git commit -m "Initial commit"
   git remote add origin https://github.com/YOUR_USERNAME/YOUR_REPO.git
   git branch -M main
   git push -u origin main
   ```

2. **GitHub Actions จะ trigger โดยอัตโนมัติ**
   - ไปที่ tab "Actions" บน GitHub
   - เลือก "Build Tweak IPA" workflow
   - ดู progress ของ build

3. **Download Artifacts**
   - รอให้ build เสร็จ
   - ไปที่ "Actions" → workflow run ที่เสร็จ
   - Download "build-artifacts"
   - จะได้ไฟล์ `.ipa` และ `.deb`

### File Structure ที่สร้าง:

```
.github/workflows/
└── build-tweak.yml          # GitHub Actions workflow
scripts/
└── deb-to-ipa.sh           # Script แปลง DEB → IPA
BUILD_INSTRUCTIONS.md        # ไฟล์นี้
.gitignore                   # ไฟล์เพื่อไม่ upload build artifacts
```

### สิ่งที่ workflow ทำ:

1. ✅ Checkout โค้ด
2. ✅ Setup Theos บน macOS runner
3. ✅ Install dependencies (ldid, xz)
4. ✅ Build tweak (`make clean && make package`)
5. ✅ Convert DEB → IPA
6. ✅ Upload artifacts
7. ✅ Create GitHub Release (ถ้า push tag)

### หมายเหตุ:

- GitHub Actions ใช้ macOS runner ฟรี 3000 นาที/เดือน
- Build time ~5-10 นาที
- ไฟล์ IPA ที่สร้างจะมี dylib library จากโปรเจกต์

---

**ต้องการลองทดสอบหรือยัง?** กด "Run workflow" ใน GitHub Actions หรือ push commit ใหม่
