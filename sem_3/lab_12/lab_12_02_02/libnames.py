libname = "libs/libarr.so"

# Проверка существования библиотеки
try:
    f = open(libname, "r")
    f.close()
except:
    print("ERROR: Library not exist")
    exit(1)
