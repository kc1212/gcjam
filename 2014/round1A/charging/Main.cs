using System;
using System.Linq;
using System.Collections.Generic;

public class ChargingChaos
{
    static int Main(string[] args)
    {
        int T = Convert.ToInt32(Console.ReadLine());

        for (int i = 0; i < T; i++) {
            string[] tmp = Console.ReadLine().Split(' ');
            int N = Convert.ToInt32(tmp[0]); // num of sockets
            int L = Convert.ToInt32(tmp[1]); // size of each socket
            // Console.WriteLine("N: {0}, L: {1}", N, L);

            List<int> devices = new List<int>();
            List<int> outlets = new List<int>();
            string[] tmpDevices = Console.ReadLine().Split(' ');
            string[] tmpOutlets = Console.ReadLine().Split(' ');

            // no need to loop around L since we're parsing base 2
            for (int j = 0; j < N; j++) {
                devices.Add(Convert.ToInt32(tmpDevices[j], 2));
                outlets.Add(Convert.ToInt32(tmpOutlets[j], 2));
            }

            int res = FindMinSwitchCount(devices, outlets);
            Console.Write("Case #{0}: ", i+1);
            if (res == -1)
                Console.WriteLine("NOT POSSIBLE");
            else
                Console.WriteLine(res);
        }

        return 0;
    }

    static int FindMinSwitchCount(List<int> devices, List<int> outlets)
    {
        // construct a table of devices xor outlets
        List<List<int>> table = new List<List<int>>();

        for (int i = 0; i < devices.Count(); i++) {
            table.Add(new List<int>());
            for (int j = 0; j < outlets.Count(); j++) {
                table[i].Add(devices[i] ^ outlets[j]);
            }
        }

        // now check if there is a common number in all the rows
        List<int> counts = new List<int>(table[0]);
        for (int i = 1; i < table.Count(); i++) {
            for (int j = 0; j < counts.Count(); j++) {
                if (!table[i].Contains( counts[j] )) {
                    counts.RemoveAt(j);
                    j -= 1;
                    if (counts.Count() < 1)
                        return -1;
                }
            }
        }

        // return the minimum
        counts.Sort();
        return SparseBitcount(counts[0]);
    }

    static int SparseBitcount(int n)
    {
        int count = 0;
        while (n != 0) {
            count++;
            n &= (n - 1);
        }
        return count;
    }
}



