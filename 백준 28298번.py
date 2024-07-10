from collections import Counter

def make_input():
    n, m, k = map(int, input().split())
    metrix = [list(input().rstrip()) for _ in range(n)]
    #n, m, k = 4, 6, 2
    #metrix = [  ["A","B","C","B","A","B"],["B","B","A","C","C","A"],["B","P","A","Z","B","B"],["B","B","A","A","B","B"]  ]
    return n, m, k, metrix

def devide_into_kk(n, m, k, metrix):
    new_metrix = []
    for i in range(0, n, k):
        for j in range(0, m, k):
            inlist = []
            for a in range(k):
                for x in range(k):
                    inlist.append(metrix[i+a][j+x])
            new_metrix.append(inlist)
    return new_metrix

def find_alpha_and_make_metrix(k, metrix):
    count_similarity = k**2
    new_metrix = metrix[:]
    for i in range(k**2):
        column = [new_metrix[j][i] for j in range(len(new_metrix))]
        most_fre_alpha, freq = Counter(column).most_common(1)[0]
        count_similarity += freq - 1
        for j in range(len(new_metrix)):
            new_metrix[j][i] = most_fre_alpha
    return new_metrix[0], count_similarity

def print_min_tile(n, m, k, one_min_tile):
    one_min_tile = "".join(one_min_tile)
    restore = [one_min_tile[i*k:i*k+k] for i in range(k)]
    cal = n // k
    row = m // k
    new_restore = [i * row for i in restore]
    for _ in range(cal):
        for i in range(len(new_restore)):
            print(new_restore[i])

def main():
    n, m, k, metrix = make_input()
    new_metrix = devide_into_kk(n, m, k, metrix)
    one_min_tile, count_similarity = find_alpha_and_make_metrix(k, new_metrix)
    min_tile_change = n * m - count_similarity
    print(min_tile_change)
    print_min_tile(n, m, k, one_min_tile)

main()
