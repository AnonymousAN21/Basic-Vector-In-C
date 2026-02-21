
---

# Basic C Generic Vector Library

Library vector generik berbasis OOP-style di bahasa C menggunakan `void*` dan function pointer untuk mendukung berbagai tipe data.

Library ini mendukung:

* Dynamic resizing (auto grow)
* push_back
* pop dengan output parameter
* get by index
* length
* isEmpty
* clear
* destroy

---

## Author

Developed and designed by **Andrew Tangel**

Computer Science Student
Full Stack Engineer
Founder of ISCO (Integrated Student Community)

---

## Project Structure

```
basic-cLibs/
│
├── main.c
├── libs/
│   ├── include/
│   │   └── vector.h
│   └── src/
│       ├── vector.c
│       └── search.c
```

---

## How To Compile and Run

Gunakan perintah berikut dari root project:

```
gcc main.c ./libs/src/search.c ./libs/src/vector.c -Ilibs/include -o test.exe
```

Lalu jalankan:

```
test.exe
```

Penjelasan:

* `-Ilibs/include` menambahkan header path
* `vector.c` adalah implementasi vector
* `search.c` jika menggunakan modul pencarian tambahan

---

# How To Use The Vector

## 1. Include Header

```
#include "vector.h"
```

---

## 2. Initialize Vector (Constructor)

```
vector v;
vector_init(&v, sizeof(int), 2);
```

Parameter:

* `sizeof(int)` → ukuran tipe data
* `2` → initial capacity

Untuk tipe lain:

```
vector_init(&v, sizeof(double), 4);
vector_init(&v, sizeof(struct MyStruct), 10);
```

---

## 3. Push Value (push_back)

```
int value = 10;
v.push_back(&v, &value);
```

Data akan disalin ke internal memory vector.

---

## 4. Get Value by Index

```
int* result = (int*) v.get(&v, 0);

if(result != NULL) {
    printf("%d\n", *result);
}
```

Catatan:

* `get` mengembalikan pointer ke internal memory
* Tidak perlu free

---

## 5. Pop Element

```
int removed;
if(v.pop(&v, 0, &removed)) {
    printf("Removed: %d\n", removed);
}
```

Element dihapus dan nilainya disalin ke `removed`.

---

## 6. Check If Empty

```
if(v.isEmpty(&v)) {
    printf("Vector is empty\n");
}
```

---

## 7. Get Length

```
size_t len = v.length(&v);
```

---

## 8. Clear Vector

```
v.clear(&v);
```

Menghapus semua element tanpa membebaskan capacity.

---

## 9. Destroy Vector (Destructor)

```
v.destroy(&v);
```

Wajib dipanggil sebelum program selesai untuk mencegah memory leak.

---

# Example Full Program

```
#include <stdio.h>
#include "vector.h"

int main() {

    vector v;
    vector_init(&v, sizeof(int), 2);

    int x = 10;
    v.push_back(&v, &x);

    x = 20;
    v.push_back(&v, &x);

    for(size_t i = 0; i < v.length(&v); i++) {
        int* val = (int*) v.get(&v, i);
        printf("%d\n", *val);
    }

    int removed;
    v.pop(&v, 0, &removed);

    v.destroy(&v);
    return 0;
}
```

---

# Design Notes

* Generic implementation menggunakan `void*`
* Memory management dilakukan secara manual
* Resize otomatis saat capacity penuh
* API dirancang menyerupai OOP pattern dalam C

---

# License

This project is free to use for academic and educational purposes.
