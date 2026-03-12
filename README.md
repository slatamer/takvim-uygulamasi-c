# 📅 C ile Dinamik Takvim Uygulaması

Bu proje, C programlama diliyle geliştirilmiş bir konsol uygulamasıdır. Kullanıcının girdiği herhangi bir yılın (1910-2090) tüm aylarını doğru gün dizilimiyle listeler.

## Teknik Arka Plan: Zeller Algoritması
Projenin kalbinde, belirli bir tarihin haftanın hangi gününe denk geldiğini hesaplayan **Zeller Congruence (Zeller Denkliği)** algoritması yer almaktadır. Bu sayede program, herhangi bir veri tabanına ihtiyaç duymadan matematiksel formüllerle takvimi oluşturur.

## Öne Çıkan Özellikler
- **Artık Yıl Kontrolü:** Şubat ayının 28 veya 29 gün olma durumunu otomatik hesaplar.
- **Hafta Sonu Vurgusu:** Hafta sonu günlerini konsolda kırmızı renk ile görselleştirir.
- **Etkileşimli Arayüz:** Kullanıcı dostu menü ve ESC ile güvenli çıkış imkanı.
- **Veri Doğrulama:** Geçersiz yıl girişlerini kontrol eden döngü yapısı.

## Kullanılan Teknolojiler
- **Dil:** C
- **Algoritma:** Zeller Congruence
- **Görselleştirme:** ANSI Escape Codes (Renkler için) ve ASCII Tablo Tasarımı

## Çalıştırma
1. `.sln` dosyasını Visual Studio ile açın.
2. `main.c` dosyasını derleyip çalıştırın.
3. Belirtilen alana istediğiniz yılı girerek o yıla ait takvimi görebilirsizin.
