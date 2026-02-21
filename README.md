
---

# Basic C STL(Standard Library)

STL generik berbasis OOP-style di bahasa C menggunakan `void*` dan function pointer untuk mendukung berbagai tipe data. library ini saya buat untuk latihan saya dalam menggunakan C.

Library ini mendukung:

* Dynamic resizing (auto grow)
* push_back
* pop dengan output parameter
* get by index
* length
* isEmpty
* clear
* destroy
* enqueue
* dequeue
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

Jika menggunakan queue + vector + search:

```
gcc main.c ./libs/src/search.c ./libs/src/vector.c ./libs/src/queue.c -Ilibs/include -o test.exe
```

Penjelasan tambahan:

* `queue.c` adalah implementasi queue
* `-Ilibs/include` menambahkan header path
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
Oke Andrew 🔥 gue tambahin dokumentasi **How To Use Queue** dengan style yang konsisten sama dokumentasi vector lo.

Lo bisa langsung copy–paste bagian ini ke README project lo 👇


---

# How To Use The Queue

## 1. Include Header

```
#include "queue.h"
```

---

## 2. Initialize Queue (Constructor)

```
queue q;
Queue(&q, sizeof(int), 5);
```

Parameter:

* `sizeof(int)` → ukuran tipe data
* `5` → kapasitas maksimum queue

Untuk tipe lain:

```
Queue(&q, sizeof(double), 10);
Queue(&q, sizeof(struct MyStruct), 20);
```

---

## 3. Enqueue (Insert Data)

```
int value = 10;
q.enqueue(&q, &value);
```

Data akan disalin ke internal memory queue.

---

## 4. Dequeue (Remove & Get Data)

Jika `dequeue` mengembalikan pointer:

```
int removed = *(int*) q.dequeue(&q);
printf("Removed: %d\n", removed);
```

Jika menggunakan output parameter (recommended):

```
int removed;
q.dequeue(&q, &removed);
printf("Removed: %d\n", removed);
```

---

## 5. Check If Empty

```
if(q.isEmpty(&q)) {
    printf("Queue is empty\n");
}
```

---

## 6. Clear Queue

```
q.clear(&q);
```

Menghapus semua elemen tanpa membebaskan capacity.

---

## 7. Destroy Queue

```
q.destroy(&q);
```

Wajib dipanggil sebelum program selesai untuk mencegah memory leak.

---

# Example Full Program (Queue Only)

```
#include <stdio.h>
#include "queue.h"

int main(){

    queue q;
    Queue(&q, sizeof(int), 5);

    int x = 10;
    q.enqueue(&q, &x);

    x = 20;
    q.enqueue(&q, &x);

    while(!q.isEmpty(&q)){
        int value = *(int*)q.dequeue(&q);
        printf("%d\n", value);
    }

    q.destroy(&q);
    return 0;
}
```

---

# Example Usage: BFS Using Your Queue

Berikut contoh penggunaan queue untuk implementasi BFS pada graph adjacency matrix.

```
#include "search.h"
#include "vector.h"
#include "queue.h"
#include <stdio.h>
#include <stdbool.h>

#define N 5

void BFS(int graph[N][N], int start){

    queue q;
    Queue(&q, sizeof(int), N);

    bool visited[N] = {false};

    q.enqueue(&q, &start);
    visited[start] = true;

    while(!q.isEmpty(&q)){

        int current = *(int*)q.dequeue(&q);
        printf("%d ", current);

        for(int i = 0; i < N; i++){
            if(graph[current][i] == 1 && !visited[i]){
                visited[i] = true;
                q.enqueue(&q, &i);
            }
        }
    }

    q.clear(&q);
}
```

Output:

```
0 1 3 2 4
```

---

# Design Notes (Queue)

* Generic implementation menggunakan `void*`
* FIFO behavior
* Data disalin ke internal buffer
* OOP-style function pointer dalam struct
* Cocok untuk:

  * BFS
  * Level order traversal
  * Task scheduling
  * Simulation system

---

# License

This project is free to use for academic and educational purposes.
