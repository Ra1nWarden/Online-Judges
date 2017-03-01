calc :: Int -> Int -> Int
calc x y = if mod x y == 0 then 0 else (mod x y) * 10 + 1

findAns :: Int -> Int -> Int
findAns x 0 = 0
findAns x y = findAns x (calc y x) + 1

v = filter (\x -> gcd x 10 == 1) [1000001..10050001]
ans = head $ dropWhile (\x -> findAns x 1 <= 1000000) v
