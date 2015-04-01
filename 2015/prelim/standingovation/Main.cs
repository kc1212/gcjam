using System;
using System.Linq;
using System.Collections.Generic;

public class StandingOvation
{

    public static int Main(string[] args)
    {
        int T = Convert.ToInt32(Console.ReadLine());

        for (int i = 0; i < T; i++) {
            string[] tmp = Console.ReadLine().Split(' ');
            // int S = Convert.ToInt32(tmp[0]);
            List<int> k= tmp[1].ToCharArray().Select(s => Convert.ToInt32(s) - 48).ToList();

            Console.WriteLine("Case #{0}: {1}", i+1, solve(k));
        }
        return 0;
    }

    private static int solve(List<int> k)
    {
        int tot = 0;
        int friends = 0;

        tot += k[0];
        for (int i = 1; i < k.Count; i++) {
            // Console.WriteLine("{0}, {1}, {2}", i, k[i], tot);
            if (k[i] != 0 && i > tot) {
                friends += i - tot;
                tot += i - tot;
            }
            tot += k[i];
        }
        return friends;
    }
}



