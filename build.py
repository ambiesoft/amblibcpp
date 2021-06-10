import sys
import timeit
import subprocess

sys.path.append('../distSolution')

import distSolution

# sample
# devenv "%USERPROFILE%\source\repos\MySolution.sln" /build Debug /project "CSharpWinApp\CSharpWinApp.csproj" /projectconfig Debug
def main():
    devenvexe = distSolution.getDevenvExeOrCom('AmbLibcpp.sln', '.com')
    if not devenvexe:
        errorexit("MSBuild not found.")

    # platform-x64
    args = [
        devenvexe,
        'AmbLibcpp.sln',
        '/build',
        'Release|x64',
        '/project',
        R'AmbLibcpp.platform\AmbLibcppPlatform.vcxproj',
        '/projectconfig',
        'Release|x64',
    ]
    print(args)
    subprocess.check_call(args)


    # platform-win32
    args = [
        devenvexe,
        'AmbLibcpp.sln',
        '/build',
        'Release|Win32',
        '/project',
        R'AmbLibcpp.platform\AmbLibcppPlatform.vcxproj',
        '/projectconfig',
        'Release|Win32',
    ]
    print(args)
    subprocess.check_call(args)


    # aambLibcpp-AnyCPU (actually AnyCPU)
    args = [
        devenvexe,
        'AmbLibcpp.sln',
        '/build',
        'Release|Win32',
        '/project',
        R'AmbLibcpp\AmbLibcpp.csproj',
        '/projectconfig',
        'Release|Any CPU',
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