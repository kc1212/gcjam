import System.IO
import Data.List
import Control.Monad

data Result = XWon | OWon | Draw | NotCompleted deriving (Show, Eq)

showResult :: Result -> String
showResult XWon = "X won"
showResult OWon = "O won"
showResult Draw = "Draw"
showResult NotCompleted = "Game as not completed"

checkDiagonal :: [String] -> (Char -> Bool) -> Bool
checkDiagonal inp cmp =
    let finp = concat inp
        group1 = [finp!!0, finp!!5, finp!!10, finp!!15]
        group2 = [finp!!3, finp!!6, finp!!9,  finp!!12]
    in all cmp group1 || all cmp group2

findState :: [String] -> Result
findState board =
    let checkx x = x == 'X' || x == 'T'
        checko o = o == 'O' || o == 'T'
    in  if any (all checkx) board || any (all checkx) (transpose board) || checkDiagonal board checkx
            then XWon
        else if any (all checko) board || any (all checko) (transpose board) || checkDiagonal board checko
            then OWon
        else if all (/='.') (concat board)
            then Draw
        else NotCompleted

readState :: IO [String]
readState = do
    res <- replicateM 4 (hGetLine stdin)
    hGetLine stdin -- for the new line
    return res

printResults :: [Result] -> Int -> IO ()
printResults [res] tot = putStrLn ("Case #" ++ show tot ++ ": " ++ (showResult res))
printResults all@(x:xs) tot =
    putStrLn ("Case #" ++ show (tot - length all + 1) ++ ": " ++ (showResult x)) >> printResults xs tot

main = do
    t <- fmap read (hGetLine stdin)
    res <- replicateM t (fmap findState readState)
    printResults res t


