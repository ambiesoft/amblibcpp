import ../distSolution/distSoluton


def main():
    msbuild = getMsBuildExe()
    if not msbuild:
        errorexit("MSBuild not found.")

def errorexit(error):
    print(error)
    exit(1)

if __name__ == "__main__":
    # codetest()

    start = timeit.default_timer()
    main()
    stop = timeit.default_timer()

    m, s = divmod(stop - start, 60)
    h, m = divmod(m, 60)
    elapsed = "%d:%02d:%02d" % (h, m, s)
    print("Disribution Succeeded (elapsed: {})".format(elapsed))