calc :: Int -> Int -> Int
calc x y = if mod x y == 0 then 0 else (mod x y) * 10 + 1

findAns :: Int -> Int -> Int
findAns x 0 = 0
findAns x y = findAns x (calc y x) + 1

a :: Int -> Int
a x = findAns x 1

composite :: Int -> Bool
composite x = not $ null $ filter (\a -> mod x a == 0) $ takeWhile (\a -> a * a <= x ) [2..x-1]

v = filter (\x -> gcd x 10 == 1 && composite x) [3..10000000]
ans = sum $ take 25 $ filter (\x -> mod (x-1) (a x) == 0) v
