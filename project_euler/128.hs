import Data.Function (on)
import Data.List (sortBy)

factors :: Integer -> [Integer]
factors x = takeWhile (\a -> a * a <= x) [2..x-1]

isPrime :: Integer -> Bool
isPrime x = null [a | a <- (factors x), x `mod` a == 0]

isPrimeList :: [Integer] -> Bool
isPrimeList [] = True
isPrimeList (x:tl) = isPrime x && isPrimeList tl

corner = [(2 + (sum [1..x]) * 6, [(x + 1) * 6 + 1, (x + 1) * 6 - 1, (x + 1 + x + 2) * 6 - 1]) | x <- [1..80000]]
side = [((sum [1..x]) * 6 + 1, [x * 6 - 1, (x + 1) * 6 - 1, (x + x - 1) * 6 - 1]) | x <- [2..80000]]

filterCandidate :: (a, [Integer]) -> Bool
filterCandidate (_, b) = isPrimeList b

corner_ok = filter filterCandidate corner
side_ok = filter filterCandidate side

ans_sorted = sortBy (compare `on` fst) ([(1, [2,3,5]), (2, [7,5,17])] ++ corner_ok ++ side_ok)
