# get_next_line - Reading a Line From a File Descriptor is Easy!

Bu proje, bir dosya tanımlayıcısından (FD) okuma yaparak her çağrıldığında bir satır döndüren bir fonksiyon geliştirmeyi amaçlar. Standart C kütüphanesinde bulunmayan bu özellik, dosya okuma işlemlerini çok daha yönetilebilir hale getirir.

---

## Özellikler

- **Esnek Okuma:** Dosya boyutu ne olursa olsun, belleği verimli kullanarak satır satır okuma yapar.
- **Birden Fazla Dosya Tanımlayıcısı:** Aynı anda birden fazla dosyadan (Multi-FD) çakışma yaşamadan okuma yapabilme desteği (Bonus).
- **Özelleştirilebilir Tampon Boyutu:** `BUFFER_SIZE` parametresi ile okuma hızının ve bellek kullanımının optimize edilebilmesi.
- **Kesintisiz Akış:** Dosya sonuna (EOF) kadar her çağrıda bir sonraki satırı hatasız şekilde döndürür.

---

## Teknik Kazanımlar

Bu projeyi geliştirirken C programlamanın şu derin teknik konularında uzmanlık kazandım:
- **Statik Değişkenler (Static Variables):** Fonksiyon çağrıları arasında verinin korunmasını sağlayarak okuma konumunun takibi.
- **Dinamik Bellek Yönetimi:** Okunan verilerin `malloc` ve `free` ile yönetilmesi, bellek sızıntılarının (memory leaks) önlenmesi.
- **File Descriptors:** İşletim sistemi seviyesinde dosya açma, okuma ve kapatma süreçlerinin yönetimi.
- **Buffer Yönetimi:** Büyük dosyaları küçük parçalar halinde okuyup satırları doğru şekilde birleştirme (concatenation) mantığı.

---

## Kurulum ve Kullanım

1. **Depoyu klonlayın:**
   ```bash
   git clone [https://github.com/AbdullahTahaUstunsoy/get_next_line.git](https://github.com/AbdullahTahaUstunsoy/get_next_line.git)
   cd get_next_line
2. Projenize dahil edin: Fonksiyonu kullanmak için get_next_line.h başlık dosyasını projenize dahil etmeniz ve ilgili .c dosyalarını derleme sürecine eklemeniz yeterlidir.
3. Derleme yapın: Derleme sırasında tampon boyutunu belirlemek için -D BUFFER_SIZE=xx bayrağını kullanabilirsiniz. Örnek: gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10 main.c get_next_line.c get_next_line_utils.c.
4. Kullanım: Bir döngü içerisinde get_next_line(fd) fonksiyonunu çağırarak dosya sonuna kadar tüm satırları tek tek elde edebilirsiniz.
