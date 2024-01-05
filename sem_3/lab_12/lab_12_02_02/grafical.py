import tkinter as tk
import tkinter.messagebox as box

import fibonacci as fib
import uniq_nums as uniq

# Цвета
WIN_BG_COLOR = "#121212"
LABEL_FG_COLOR = "#f1f1f1"
BUTTON_BG_COLOR = "#1d1d1d"
BUTTON_FG_COLOR = "#9e9e9e"

INDEX_FG_COLOR = "#858585"
INDEX_BG_COLOR = "#272727"

ERROR_COLOR = "#e31c1c"

# Максимальные размеры
MAX_FIB_CNT = 40
MAX_ARR_LEN = 20


# Функция увеличения числа на один до определенного максимума
def increase_number(entry: tk.Entry, _max: int):
    current_value = int(entry.get())
    entry.delete(0, tk.END)
    entry.insert(0, str(current_value + 1 if current_value + 1 <= _max else current_value))


# Функция увеличения числа на один до нуля максимума
def decrease_number(entry: tk.Entry):
    current_value = int(entry.get())
    entry.delete(0, tk.END)
    entry.insert(0, str(current_value - 1 if current_value - 1 > 0 else 0))


# Вывод массива
def write_arr(win, _arr: [int]):
    row_i = 0
    MAX_NUM_ON_ROW = 10
    for i, num in enumerate(_arr):
        if i % MAX_NUM_ON_ROW == 0 and i // MAX_NUM_ON_ROW != 0:
            row_i += 2
        index_label = tk.Label(win, text=str(i + 1), bg=INDEX_BG_COLOR, fg=INDEX_FG_COLOR, font=('Arial', 8),
                               relief=tk.RIDGE, padx=5, pady=2)
        index_label.grid(row=row_i, column=i % MAX_NUM_ON_ROW, sticky="WENS")
        num_label = tk.Label(win, text=str(num), bg=WIN_BG_COLOR, fg=LABEL_FG_COLOR, font=('Arial', 12),
                             relief=tk.RIDGE, width=10)
        num_label.grid(row=row_i + 1, column=i % MAX_NUM_ON_ROW)


# Вывод массива уникальных значений в отдельном окне
def uniq_arr_out(_is_find_size: tk.BooleanVar):
    str_arr = arr_entr.get()
    if len(str_arr) == 0 or (len(str_arr) == 1 and str_arr[-1] == "-"):
        box.showinfo("Error", "Array is empty")
        return
    
    if str_arr[-1] == "-":
        str_arr = str_arr[:-1]
    src_arr = list(map(int, str_arr.rstrip().split()))

    uniq_window = tk.Toplevel(window)
    uniq_window.title("Uniq numbers array")
    uniq_window["bg"] = WIN_BG_COLOR

    uniq_arr = uniq.uniqcpy(src_arr, _is_find_size.get())
    write_arr(uniq_window, uniq_arr)


# Вывод чисел Фибоначчи в отдельном окне
def fibonacci_out():
    fib_nums_cnt = int(fib_cnt.get())

    if fib_nums_cnt == 0 or fib_nums_cnt > 40:
        box.showerror("Error range", "0 < cnt <= 40")
        return

    fib_window = tk.Toplevel(window)
    fib_window.title("Generated Fibonacci Numbers")
    fib_window["bg"] = WIN_BG_COLOR

    fib_nums = fib.fill_fibonacci(fib_nums_cnt)
    write_arr(fib_window, fib_nums)


# Создания окна
window = tk.Tk()
window.title("lab_12_02_02")
window.resizable(None, None)
window["bg"] = WIN_BG_COLOR

# Числа Фибоначчи
# start_fib-------------------------------------------------------------------------------------------------------------
fib_lab = tk.Label(window, text="Fibonacci nums cnt:",
                   fg=LABEL_FG_COLOR, bg=WIN_BG_COLOR, font=("Arial", 12))
fib_lab.grid(row=0, column=0, padx=10, pady=10, sticky="E")

fibcnt_frame = tk.Frame(window, bg=WIN_BG_COLOR, highlightthickness=0)
fibcnt_frame.grid(row=0, column=1, padx=10, pady=10, sticky="WE")

fib_cnt = tk.Entry(fibcnt_frame, bg=WIN_BG_COLOR, fg=LABEL_FG_COLOR, font=('Arial', 12),
                   width=5, highlightthickness=0, )
fib_cnt.insert(0, "0")
fib_cnt.grid(row=0, column=1, padx=0, pady=10, sticky="W")
# Запрет ввода не положительных чисел(Разрешает удалять)
fib_cnt.bind("<Key>", lambda e:
             "break" if not (e.char.isdigit() or e.keysym == "BackSpace")
             else None)
# Запись нуля если поле пустое
fib_cnt.bind("<FocusOut>", lambda e:
             fib_cnt.insert(tk.END, "0") if not fib_cnt.get()
             else None)

# Кнопка увеличения количества чисел Фибоначчи
plus_btn = tk.Button(fibcnt_frame, text="+", width=5,
                     command=lambda: increase_number(fib_cnt, MAX_FIB_CNT),
                     bg=BUTTON_BG_COLOR, fg=BUTTON_FG_COLOR,
                     relief=tk.FLAT, highlightthickness=0,
                     font=('Arial', 12))
plus_btn.grid(row=0, column=2, padx=0, pady=5, sticky="W")

# Кнопка уменьшения количества чисел Фибоначчи
minus_btn = tk.Button(fibcnt_frame, text="-", width=5,
                      command=lambda: decrease_number(fib_cnt),
                      bg=BUTTON_BG_COLOR, fg=BUTTON_FG_COLOR,
                      relief=tk.FLAT, highlightthickness=0,
                      font=('Arial', 12))
minus_btn.grid(row=0, column=0, padx=0, pady=5, sticky="W")

# Кнопка генерации чисел Фибоначчи
fib_gen = tk.Button(window, text="Gen Fibonacci nums", bg=BUTTON_BG_COLOR, fg=BUTTON_FG_COLOR,
                    font=('Arial', 12), bd=0, highlightthickness=0,
                    command=fibonacci_out)
fib_gen.grid(row=1, column=0, columnspan=2, padx=10, pady=0, sticky="WE")

# end_fib---------------------------------------------------------------------------------------------------------------

# Копирование уникальных элементов исходного массива
# start_uniq------------------------------------------------------------------------------------------------------------

arr_lab = tk.Label(window, text="Array:", fg=LABEL_FG_COLOR, bg=WIN_BG_COLOR, font=("Arial", 12))
arr_lab.grid(row=3, column=0, columnspan=2, padx=10, pady=10, sticky="WE")

# Поле ввода массива
arr_entr = tk.Entry(window, bg=WIN_BG_COLOR, fg=LABEL_FG_COLOR, font=('Arial', 12),
                    width=5, highlightthickness=0, )
arr_entr.grid(row=4, column=0, columnspan=2, padx=10, pady=10, sticky="WE")
# Валидация ввода массива
arr_entr.bind("<Key>", lambda e:
              "break" if not (e.char.isdigit()
                              or (e.char == '-' and
                                  ((len(arr_entr.get()) == 0 or
                                    not arr_entr.get()[-1].isdigit() and arr_entr.get()[-1] != "-")))
                              or e.keysym == "BackSpace"
                              or (e.char.isspace()
                                  and (len(arr_entr.get()) and arr_entr.get()[-1].isdigit())))
              else None)

# Переменная определяющая выделения памяти под новый массив
# True - искать размер будущего массива
# False - Выделять память с запасом
is_find_size = tk.BooleanVar()
is_find_size.set(True)


# Размер нового массива ищется
def find_arr_size(is_find_size_label):
    is_find_size_label.set(True)
    find_size.config(bg=BUTTON_FG_COLOR, fg=BUTTON_BG_COLOR)
    sup_size.config(bg=BUTTON_BG_COLOR, fg=BUTTON_FG_COLOR)


# Размер нового массива определяется с запасом
def suppose_arr_size(is_find_size_label):
    is_find_size_label.set(False)
    sup_size.config(bg=BUTTON_FG_COLOR, fg=BUTTON_BG_COLOR)
    find_size.config(bg=BUTTON_BG_COLOR, fg=BUTTON_FG_COLOR)


# Кнопка сообщающая о том что размер надо искать
find_size = tk.Button(window, text="Find arr size",
                      bg=BUTTON_FG_COLOR, fg=BUTTON_BG_COLOR, font=('Arial', 12),
                      bd=0, highlightthickness=0, width=15, relief=tk.FLAT,
                      command=lambda: find_arr_size(is_find_size))
find_size.grid(row=5, column=0, padx=10, pady=10, sticky="WE")

# Кнопка сообщающая о том что размер надо выделить с запасом
sup_size = tk.Button(window, text="Suppose arr size",
                     bg=BUTTON_BG_COLOR, fg=BUTTON_FG_COLOR, font=('Arial', 12),
                     bd=0, highlightthickness=0, width=15, relief=tk.FLAT,
                     command=lambda: suppose_arr_size(is_find_size))
sup_size.grid(row=5, column=1, padx=10, pady=10, sticky="WE")

# Кнопка создания массива уникальных значений исходного массива
arr_uniq = tk.Button(window, text="Get unique nums", bg=BUTTON_BG_COLOR, fg=BUTTON_FG_COLOR,
                     font=('Arial', 12), bd=0, highlightthickness=0,
                     command=lambda: uniq_arr_out(is_find_size))
arr_uniq.grid(row=6, column=0, columnspan=2, padx=10, pady=10, sticky="WE")

# end_uniq--------------------------------------------------------------------------------------------------------------

window.mainloop()  # Зацикливание окна


def win_draw():
    pass
