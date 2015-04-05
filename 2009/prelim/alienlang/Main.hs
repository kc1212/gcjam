
import System.IO
import Data.Char
import Control.Applicative
import Control.Monad

solve :: [String] -> String -> Bool
solve rule word =
    if length word /= length rule
        then False
        else all (\(x,y) -> x `elem` y) (zip word rule)

parse :: String -> [String]
parse [] = []
parse (x:xs) =
    case x of
        '(' -> let z = span isAlpha xs in [fst z] ++ parse (tail $ snd z)
        _   -> if isAlpha x then [[x]] ++ parse xs else error "parse error"

main = do
    [l,d,n] <- map read . words <$> getLine
    ds <- replicateM d getLine
    ns <- replicateM n getLine
    forM_ (zip ns [1..n]) $ \(n,c) -> do
        let count = length . filter (\x -> x) $ map (solve (parse n)) ds
        putStrLn $ "Case #" ++ show c ++ ": " ++ (show count)


