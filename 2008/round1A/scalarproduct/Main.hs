
import Control.Applicative
import Control.Monad
import Data.List

solve :: [Integer] -> [Integer] -> Integer
solve xs ys =
    let product x y = sum $ map (\(a,b) -> a*b) (zip x y)
    in product (reverse $ sort xs) (sort ys)

main = do
    t <- readLn
    forM_ [1..t] $ \c -> do
        _ <- getLine -- disgard
        xs <- map read . words <$> getLine
        ys <- map read . words <$> getLine
        putStrLn $ "Case #" ++ show c ++ ": " ++ (show $ solve xs ys)

