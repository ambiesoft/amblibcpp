import sys
import timeit
import subprocess

sys.path.append('../distSolution')

import distSolution


def main():
    msbuildexe = distSolution.getMsBuildExe('AmbLibcpp.2013.sln')
    if not msbuildexe:
        errorexit("MSBuild not found.")

    # platform-x64
    args = [
        msbuildexe,
        'AmbLibcpp.2013.sln',
        '/t:AmbLibcpp_platform',
        '/p:Configuration=Release',
        '/p:Platform=x64',
    ]
    print(args)
    subprocess.check_call(args)


    # platform-win32
    args = [
        msbuildexe,
        'AmbLibcpp.2013.sln',
        '/t:AmbLibcpp_platform',
        '/p:Configuration=Release',
        '/p:Platform=Win32',
    ]
    print(args)
    subprocess.check_call(args)


    # aambLibcpp-win32 (actually AnyCPU)
    args = [
        msbuildexe,
        'AmbLibcpp.2013.sln',
        '/t:AmbLibcpp',
        '/p:Configuration=Release',
        '/p:Platform=Win32',
    ]
    print(args)
    subprocess.check_call(args)



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