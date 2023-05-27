import os
import math
from prettytable import PrettyTable

progs = ["snrestrict", "restrict", "cnrestrict"]
opts = ["O3"]
runs = int(open("../measures/runs.txt").read())

def calculate_ratio(t, n, table):
    for i in range(len(t) - 1):
        ratio = (math.log(t[i + 1]) - math.log(t[i])) / (math.log(n[i + 1]) - math.log(n[i]))
        table.add_row((f"{n[i]}", f"{t[i]:.2f}", f"{ratio:.2f}"))


for prog in progs:
    for opt in opts:
        table = PrettyTable(['n','t_n', '(ln(t[i+1]) – ln(t[i])) / (ln(n[i+1]) – ln(n[i]))'])
        table.title = f"{prog}_{opt}"
        lens = os.listdir(f"../measures/{prog}/{opt}")
        for i in range(len(lens)):
            lens[i] = int(lens[i].replace(".txt", ""))
        lens.sort()
        data = []
        for length in lens:
            with open(f"../measures/{prog}/{opt}/{length}.txt") as runs_file:
                times = runs_file.read().split()
            total_sum = 0
            times = list(map(int, times))
            for time in times:
                total_sum += time
            average_time = total_sum / runs
            data.append(average_time)
        calculate_ratio(data, lens, table)
        print(table)
        print("\n\n")
