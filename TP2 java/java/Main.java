import java.util.*;

public class Main {
    // method hitung panjang kolom maksimum
    public static int maxLen(List<TV> data, int kolom) {
        int mx = 0;             // variabel untuk menyimpan panjang maksimum
        for (TV t : data) {     // loop setiap TV
            String val = "";    // simpan nilai sesuai kolom
            switch (kolom) {    // pilih atribut berdasarkan indeks kolom
                case 0: val = t.getId(); break;
                case 1: val = t.getNama(); break;
                case 2: val = String.valueOf(t.getHarga()); break;
                case 3: val = t.getMerek(); break;
                case 4: val = t.getKategori(); break;
                case 5: val = String.valueOf(t.getStok()); break;
                case 6: val = t.getUkuran(); break;
                case 7: val = t.getResolusi(); break;
                case 8: val = t.getTipeLayar(); break;
            }
            // update panjang maksimum
            if (val.length() > mx) mx = val.length();
        }
        return mx;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);            // scanner untuk input
        List<TV> daftarTV = new ArrayList<>();          // list untuk simpan data TV

        // Data awal
        daftarTV.add(new TV("T01","Samsung Neo QLED",15000000,"Samsung","TV",10,"55 inch","4K","QLED"));
        daftarTV.add(new TV("T02","LG OLED CX",18000000,"LG","TV",8,"65 inch","4K","OLED"));
        daftarTV.add(new TV("T03","Sony Bravia",20000000,"Sony","TV",6,"55 inch","4K","LED"));
        daftarTV.add(new TV("T04","Xiaomi Mi TV",7000000,"Xiaomi","TV",12,"43 inch","1080p","LED"));
        daftarTV.add(new TV("T05","Polytron Cinemax",5000000,"Polytron","TV",15,"32 inch","720p","LED"));

        // tanya user apakah ingin menambah produk
        System.out.print("Apakah ingin menambah produk baru? (y/n): ");
        char pilihan = sc.next().charAt(0);
        sc.nextLine();

        // loop jika user ingin tambah produk
        while (pilihan == 'y' || pilihan == 'Y') {
            System.out.print("Masukkan ID: ");
            String id = sc.nextLine();
            boolean found = false;          // cek apakah ID sudah ada

            // cek ID sudah ada atau belum
            for (TV tv : daftarTV) {
                if (tv.getId().equals(id)) {        // jika sudah ada
                    System.out.println("Produk dengan ID " + id + " sudah ada.");
                    System.out.print("Masukkan tambahan stok: ");
                    int tambahan = sc.nextInt();
                    sc.nextLine();
                    tv.setStok(tv.getStok() + tambahan);        // update stok
                    System.out.println("Stok berhasil diperbarui. Stok sekarang: " + tv.getStok());
                    found = true;
                }
            }

            // jika ID belum ada, input data baru
            if (!found) {
                System.out.print("Masukkan Nama: ");
                String nama = sc.nextLine();
                System.out.print("Masukkan Harga: ");
                int harga = sc.nextInt();
                sc.nextLine();
                System.out.print("Masukkan Merek: ");
                String merek = sc.nextLine();
                System.out.print("Masukkan Kategori: ");
                String kategori = sc.nextLine();
                System.out.print("Masukkan Stok: ");
                int stok = sc.nextInt();
                sc.nextLine();
                System.out.print("Masukkan Ukuran: ");
                String ukuran = sc.nextLine();
                System.out.print("Masukkan Resolusi: ");
                String resolusi = sc.nextLine();
                System.out.print("Masukkan Tipe Layar: ");
                String tipeLayar = sc.nextLine();

                // tambah produk baru ke daftar
                daftarTV.add(new TV(id, nama, harga, merek, kategori, stok, ukuran, resolusi, tipeLayar));
                System.out.println("Produk baru berhasil ditambahkan.");
            }
            // Tanya lagi apakah mau tambah produk
            System.out.print("Tambah produk lagi? (y/n): ");
            pilihan = sc.next().charAt(0);
            sc.nextLine();
        }

        // header tabel
        String[] header = {"ID","Nama","Harga","Merek","Kategori","Stok","Ukuran","Resolusi","Tipe Layar"};
        int[] width = new int[9];

        // Hitung lebar kolom max
        for (int i=0; i<9; i++) {
            width[i] = header[i].length();
            int w = maxLen(daftarTV,i);
            if (w > width[i]) width[i] = w;
        }

        // Print garis atas
        for (int i=0; i<9; i++) System.out.print("+-" + "-".repeat(width[i]) + "-");
        System.out.println("+");
        // print header tabel
        for (int i=0; i<9; i++) System.out.printf("| %-" + width[i] + "s ", header[i]);
        System.out.println("|");
        // print garis pemisah
        for (int i=0; i<9; i++) System.out.print("+-" + "-".repeat(width[i]) + "-");
        System.out.println("+");

        // Print data
        for (TV t : daftarTV) {
            System.out.printf("| %-" + width[0] + "s ", t.getId());
            System.out.printf("| %-" + width[1] + "s ", t.getNama());
            System.out.printf("| %-" + width[2] + "d ", t.getHarga());
            System.out.printf("| %-" + width[3] + "s ", t.getMerek());
            System.out.printf("| %-" + width[4] + "s ", t.getKategori());
            System.out.printf("| %-" + width[5] + "d ", t.getStok());
            System.out.printf("| %-" + width[6] + "s ", t.getUkuran());
            System.out.printf("| %-" + width[7] + "s ", t.getResolusi());
            System.out.printf("| %-" + width[8] + "s ", t.getTipeLayar());
            System.out.println("|");
        }

        // Cetak garis bawah tabel
        for (int i=0; i<9; i++) System.out.print("+-" + "-".repeat(width[i]) + "-");
        System.out.println("+");
    }
}
