import os

progs = ["adress_sort", "index_sort", "pointer_sort"]
arrs = os.listdir("data/arrs")
opts = ["O0", "O2"]
runs = int(open("../measures/runs.txt").read())

for prog in progs:
    for arr in arrs:
        for opt in opts:
            lens = os.listdir(f"../measures/{prog}/{arr}/{opt}")
            for i in range(len(lens)):
                lens[i] = int(lens[i].replace(".txt", ""))
            lens.sort()
            data=[]
            for length in lens:
                with open(f"../measures/{prog}/{arr}/{opt}/{length}.txt") as runs_file:
                    times = runs_file.read().split()
                total_sum = 0
                minn = float("+inf")
                maxx = float("-inf")
                low_kv = round(len(times) / 4)
                mid_kv = round(len(times) * 2 / 4)
                if len(times) % 2 == 0:
                    middle = (int(times[mid_kv]) + int(times[mid_kv - 1])) // 2
                else:
                    middle = times[mid_kv]
                high_kv = round(len(times) * 3 / 4)
                for time in times:
                    total_sum += int(time)
                    minn = min(int(time), minn)
                    maxx = max(int(time), maxx)
                average = total_sum / runs
                times.sort()
                data.append((length, average, minn, maxx, times[low_kv], middle, times[high_kv]))
            with open(f"calced_data/{prog}_{arr}_{opt}.txt", "w") as data_file:
                for data_str in data:
                    data_file.write(f"{data_str[0]} {data_str[1]} {data_str[2]} {data_str[3]} {data_str[4]} {data_str[5]} {data_str[6]}\n")

