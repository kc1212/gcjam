
using System;
using System.Linq;
using System.Collections.Generic;
using System.Diagnostics;

public static class Lawnmower
{
    const int C = -1;
    public static int Main(string[] args)
    {
        int T = Convert.ToInt32(Console.ReadLine());
        for (int t = 0; t < T; t++) {
            string[] tmp = Console.ReadLine().Split(' ');
            int N = Convert.ToInt32(tmp[0]);
            int M = Convert.ToInt32(tmp[1]);

            List<List<int>> lawn = new List<List<int>>();
            for (int n = 0; n < N; n++) {
                lawn.Add(parseRow(Console.ReadLine(), ' ', M));
            }
            Console.Write("Case #{0}: ", t+1);
            Console.WriteLine(isPossible(lawn) ? "YES" : "NO");

        }
        return 0;
    }

    private static void printRow(List<int> l)
    {
        l.ForEach(x => Console.Write("{0},", x));
        Console.WriteLine();
    }

    private static List<int> parseRow(string str, char delimiter, int len)
    {
        string[] tmp = str.Split(delimiter);
        Debug.Assert(tmp.Length == len);

        List<int> results = new List<int>();
        foreach (string s in tmp) {
            results.Add(Convert.ToInt32(s));
        }
        return results;
    }

    // https://stackoverflow.com/questions/19382346/using-linq-how-to-transform-a-list-of-lists-using-elements-index
    /*
    public static IEnumerable<IList<T>> Transpose<T>(this IEnumerable<IEnumerable<T>> source)
    {
        var enumerators = source.Select(e => e.GetEnumerator()).ToArray();
        try {
            while (enumerators.All(e => e.MoveNext())) {
                yield return enumerators.Select(e => e.Current).ToArray();
            }
        }
        finally {
            foreach (var enumerator in enumerators)
                enumerator.Dispose();
        }
    }
    */

    private static bool checkColumn(List<List<int>> lawn, int m, int target)
    {
        int N = lawn.Count;
        for (int n = 0; n < N; n++) {
            if (lawn[n][m] != target && lawn[n][m] != C)
                return false;
        }
        return true;
    }

    private static void setColumn(List<List<int>> lawn, int m)
    {
        int N = lawn.Count;
        for (int n = 0; n < N; n++) {
            lawn[n][m] = C;
        }
    }

    private static bool isPossible(List<List<int>> lawn)
    {
        // sorted uniques
        var su = lawn.SelectMany(d => d).ToList().Distinct().ToList();
        su.Sort();

        foreach (var i in su) {
            for (int n = 0; n < lawn.Count; n++) {
                if (lawn[n].All(x => x == i || x == C)) {
                    lawn[n] = lawn[n].Select(x => C).ToList();
                }
            }
            // check all column
            for (int m = 0; m < lawn[0].Count; m++) {
                if (checkColumn(lawn, m, i)) {
                    setColumn(lawn, m);
                }
            }
        }
        // lawn.ForEach(printRow);
        return lawn.SelectMany(d => d).All( x => x == C);
    }
}


