import System.IO
import Data.List
import Control.Monad

solve :: (Integer,Integer) -> Int
solve (start,fin) =
    -- this won't work if x is 10^100
    let mysqrt  = sqrt . fromIntegral
        test1 x = reverse (show x) == show x
        test2 x = reverse (show (x^2)) == show (x^2)
        start'  = ceiling (mysqrt start) :: Integer
        fin'    = floor (mysqrt fin) :: Integer
    in length $ filter (\x -> test1 x && test2 x) [start' .. fin']

readInput :: IO (Integer,Integer)
readInput = do
    l <- fmap words (hGetLine stdin)
    return (read (l!!0), read (l!!1))

printResults :: [Int] -> Int -> IO ()
printResults [res] tot = putStrLn ("Case #" ++ show tot ++ ": " ++ (show res))
printResults all@(x:xs) tot =
    putStrLn ("Case #" ++ show (tot - length all + 1) ++ ": " ++ (show x)) >> printResults xs tot

main = do
    t <- fmap read (hGetLine stdin)
    res <- replicateM t (fmap solve readInput)
    printResults res t


