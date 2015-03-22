
import System.IO
import Control.Monad
import Data.List

parseNM :: String -> (Int, Int)
parseNM inp =
    let tmp = map read (words inp)
    in (tmp!!0, tmp!!1)

parseLawn :: [String] -> [[Int]]
parseLawn inp = [ map read (words x) | x <- inp ]

sortedUniques :: [[Int]] -> [Int]
sortedUniques = nub . sort . concat

hasColumnOrRow :: ([Int] -> Bool) -> [[Int]] -> Bool
hasColumnOrRow cmp lawn = any cmp lawn || any cmp (transpose lawn)

isLawnPossible :: [[Int]] -> Bool
isLawnPossible lawn =
    let su = sortedUniques lawn
        test1 = hasColumnOrRow (all (head su == )) lawn
        test2 = all (\x -> hasColumnOrRow (all (<=x)) lawn) (tail su)
    in test1 && test2

readLawn :: IO [[Int]]
readLawn = do
    (n,m) <- hGetLine stdin >>= return . parseNM
    fmap parseLawn (replicateM n (hGetLine stdin))

yesno :: Bool -> String
yesno b = if b then "YES" else "NO"

printResult :: [Bool] -> Int -> IO ()
printResult [] _ = error "empty result!"
printResult [res] tot = putStrLn ("Case #" ++ show tot ++ ": " ++ (yesno res))
printResult all@(x:xs) tot =
    putStrLn ("Case #" ++ show (tot - length all + 1) ++ ": " ++ (yesno x)) >> printResult xs tot

main = do
    t <- fmap read (hGetLine stdin)
    res <- replicateM t (fmap isLawnPossible readLawn)
    printResult res t


