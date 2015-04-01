
import Control.Applicative
import Control.Monad
import Data.List

data Quaternions = O | I | J | K  deriving (Show, Eq)
data Sign x = Pos x | Neg x deriving (Show, Eq)

-- row then column
doQmult :: Quaternions -> Quaternions -> Sign Quaternions
doQmult O x = Pos x
doQmult x O = Pos x
doQmult I I = Neg O
doQmult I J = Pos K
doQmult I K = Neg J
doQmult J I = Neg K
doQmult J J = Neg O
doQmult J K = Pos I
doQmult K I = Pos J
doQmult K J = Neg I
doQmult K K = Neg O

neg :: Sign Quaternions -> Sign Quaternions
neg (Pos x) = Neg x
neg (Neg x) = Pos x

qmult :: Sign Quaternions -> Sign Quaternions -> Sign Quaternions
qmult (Pos x) (Pos y) = doQmult x y
qmult (Neg x) (Neg y) = doQmult x y
qmult (Neg x) (Pos y) = neg $ doQmult x y
qmult (Pos x) (Neg y) = neg $ doQmult x y

splitUntil :: Sign Quaternions -> Sign Quaternions -> [Sign Quaternions] -> Maybe [Sign Quaternions]
splitUntil target curr [] = if target == curr then Just [] else Nothing
splitUntil target curr (x:xs) =
    case curr == target of
        True  -> Just (x:xs)
        False -> splitUntil target (qmult curr x) xs

solve :: [Sign Quaternions] -> Bool
solve xs = (Just [] ==) $ splitUntil (Pos I) (head xs) (tail xs)
                            >>= \x -> splitUntil (Pos J) (head x) (tail x)
                            >>= \x -> splitUntil (Pos K) (head x) (tail x)

parse :: [Char] -> [Sign Quaternions]
parse [] = []
parse ('i':xs) = Pos I : parse xs
parse ('j':xs) = Pos J : parse xs
parse ('k':xs) = Pos K : parse xs
parse _ = error "error parsing"

main = do
    t <- readLn
    forM_ [1..t] $ \c -> do
        [x,l] <- map read . words <$> getLine
        ijks <- parse <$> getLine >>= return . take (x*l) . cycle
        putStrLn $ "Case #" ++ show c ++ ": " ++ (if solve ijks then "YES" else "NO")



