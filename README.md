# GLib Tests
## Description
A repository I'm using to store my progress while learning GNOME's GLib [library](https://github.com/GNOME/glib). Specifically hashing via `ghash`.

## Test Files
### GLib Structures (glib_structs.c)
In this test, we have structures as keys and values (all integers). However, the total size for each the key and value exceeds 64-bits. We also use the `g_int_hash` hashing function (along with `g_int_equal`) which works fine.

By default, the amount of entries it inserts and looks up is 5 (`MAX_ENTRIES_DEFAULT`). However, the first argument of the program determines how many entries to insert and lookup.

Please look at the following example.

```bash
./build/glib_structs 20
```

The above (after building, of course) will output the following.

```bash
dev@test02:~/glib-tests$ ./build/glib_structs 20
Successfully inserted entry! Key => 0:0:0:0 (0). Val => 0:0:0:0:0:0.
Successfully inserted entry! Key => 300:3:600:90 (1). Val => 1:2:3:4:100000:10000000.
Successfully inserted entry! Key => 600:6:1200:180 (2). Val => 2:4:6:8:200000:20000000.
Successfully inserted entry! Key => 900:9:1800:270 (3). Val => 3:6:9:12:300000:30000000.
Successfully inserted entry! Key => 1200:12:2400:360 (4). Val => 4:8:12:16:400000:40000000.
Successfully inserted entry! Key => 1500:15:3000:450 (5). Val => 5:10:15:20:500000:50000000.
Successfully inserted entry! Key => 1800:18:3600:540 (6). Val => 6:12:18:24:600000:60000000.
Successfully inserted entry! Key => 2100:21:4200:630 (7). Val => 7:14:21:28:700000:70000000.
Successfully inserted entry! Key => 2400:24:4800:720 (8). Val => 8:16:24:32:800000:80000000.
Successfully inserted entry! Key => 2700:27:5400:810 (9). Val => 9:18:27:36:900000:90000000.
Successfully inserted entry! Key => 3000:30:6000:900 (10). Val => 10:20:30:40:1000000:100000000.
Successfully inserted entry! Key => 3300:33:6600:990 (11). Val => 11:22:33:44:1100000:110000000.
Successfully inserted entry! Key => 3600:36:7200:1080 (12). Val => 12:24:36:48:1200000:120000000.
Successfully inserted entry! Key => 3900:39:7800:1170 (13). Val => 13:26:39:52:1300000:130000000.
Successfully inserted entry! Key => 4200:42:8400:1260 (14). Val => 14:28:42:56:1400000:140000000.
Successfully inserted entry! Key => 4500:45:9000:1350 (15). Val => 15:30:45:60:1500000:150000000.
Successfully inserted entry! Key => 4800:48:9600:1440 (16). Val => 16:32:48:64:1600000:160000000.
Successfully inserted entry! Key => 5100:51:10200:1530 (17). Val => 17:34:51:68:1700000:170000000.
Successfully inserted entry! Key => 5400:54:10800:1620 (18). Val => 18:36:54:72:1800000:180000000.
Successfully inserted entry! Key => 5700:57:11400:1710 (19). Val => 19:38:57:76:1900000:190000000.
Size of table is now 20 (entries).
Lookup successful! Key => 0:0:0:0 (0). Val => 0:0:0:0:0:0.
Lookup successful! Key => 300:3:600:90 (1). Val => 1:2:3:4:100000:10000000.
Lookup successful! Key => 600:6:1200:180 (2). Val => 2:4:6:8:200000:20000000.
Lookup successful! Key => 900:9:1800:270 (3). Val => 3:6:9:12:300000:30000000.
Lookup successful! Key => 1200:12:2400:360 (4). Val => 4:8:12:16:400000:40000000.
Lookup successful! Key => 1500:15:3000:450 (5). Val => 5:10:15:20:500000:50000000.
Lookup successful! Key => 1800:18:3600:540 (6). Val => 6:12:18:24:600000:60000000.
Lookup successful! Key => 2100:21:4200:630 (7). Val => 7:14:21:28:700000:70000000.
Lookup successful! Key => 2400:24:4800:720 (8). Val => 8:16:24:32:800000:80000000.
Lookup successful! Key => 2700:27:5400:810 (9). Val => 9:18:27:36:900000:90000000.
Lookup successful! Key => 3000:30:6000:900 (10). Val => 10:20:30:40:1000000:100000000.
Lookup successful! Key => 3300:33:6600:990 (11). Val => 11:22:33:44:1100000:110000000.
Lookup successful! Key => 3600:36:7200:1080 (12). Val => 12:24:36:48:1200000:120000000.
Lookup successful! Key => 3900:39:7800:1170 (13). Val => 13:26:39:52:1300000:130000000.
Lookup successful! Key => 4200:42:8400:1260 (14). Val => 14:28:42:56:1400000:140000000.
Lookup successful! Key => 4500:45:9000:1350 (15). Val => 15:30:45:60:1500000:150000000.
Lookup successful! Key => 4800:48:9600:1440 (16). Val => 16:32:48:64:1600000:160000000.
Lookup successful! Key => 5100:51:10200:1530 (17). Val => 17:34:51:68:1700000:170000000.
Lookup successful! Key => 5400:54:10800:1620 (18). Val => 18:36:54:72:1800000:180000000.
Lookup successful! Key => 5700:57:11400:1710 (19). Val => 19:38:57:76:1900000:190000000.
```

## Building
You may use `git` and `make` to build this project. You will also need `clang` and `libglib2.0`.

The following will do for Debian/Ubuntu systems.

```bash
# Run apt update as root.
sudo apt update

# Install Make and build essentials.
sudo apt install build-essential

# Install Clang if it isn't installed already.
sudo apt install clang

# Install GLib 2.0 along with pkg-config (which is used for obtaining GLib's include paths and linker libraries).
sudo apt install libglib2.0 pkg-config

# Clone the repository.
git clone https://github.com/gamemann/GLib-Tests.git

# Change directory to GLib-Tests/.
cd GLib-Tests/

# Run Make which will output executables into the build/ directory.
make
```

## Credits
* [Christian Deacon](https://github.com/gamemann)