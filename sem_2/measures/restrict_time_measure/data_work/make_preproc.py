import os

progs = ["snrestrict", "restrict", "cnrestrict"] # Программы
opts = ["O0", "O3", "Os"]  # Оптимизации
runs = int(open("../measures/runs.txt").read()) # Количество замеров

for prog in progs:
        for opt in opts:
            lens = os.listdir(f"../measures/{prog}/{opt}") # Длины массивов
            for i in range(len(lens)):
                lens[i] = int(lens[i].replace(".txt", ""))
            lens.sort() # Сортировка по возрастанию
            data=[]
            for length in lens:
                with open(f"../measures/{prog}/{opt}/{length}.txt") as runs_file:
                    times = runs_file.read().split()
                total_sum = 0
                for time in times:
                    total_sum += int(time)
                average = total_sum / runs # Среднее значение времени
                data.append((length, average)) # Запись данных в файл
            with open(f"calced_data/{prog}_{opt}.txt", "w") as data_file:
                for data_str in data:
                    data_file.write(f"{data_str[0]} {data_str[1]}\n")

