import os
import math
from prettytable import PrettyTable

def real_std_err(avg, data, data_size):
    s_sq = 0.0
    for i in range(data_size):
        s_sq += (data[i] - avg) * (data[i] - avg)
    s_sq /= (data_size - 1)
    s = math.sqrt(s_sq)
    std_err = s / math.sqrt(data_size)
    rse = std_err / avg * 100
    return rse


progs = ["snrestrict", "restrict", "cnrestrict"]
opts = ["O3"]
runs = int(open("../measures/runs.txt").read())

for prog in progs:
    for opt in opts:
        table = PrettyTable(['n','t_n', 'rse'])
        table.title = f"{prog}_{opt}"
        lens = os.listdir(f"../measures/{prog}/{opt}")
        for i in range(len(lens)):
            lens[i] = int(lens[i].replace(".txt", ""))
        lens.sort()
        for length in lens:
            with open(f"../measures/{prog}/{opt}/{length}.txt") as runs_file:
                times = runs_file.read().split()
            total_sum = 0
            times = list(map(int, times))
            for time in times:
                total_sum += time
            average_time = total_sum / runs
            rse = real_std_err(average_time, times, runs)
            table.add_row([f"{length}",f"{average_time:.2f}", f"{rse:.2f}"])
        print(table)
        print("\n\n")
