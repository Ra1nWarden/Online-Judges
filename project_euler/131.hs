isPrime :: Int -> Bool
isPrime x = null $ dropWhile (\a -> mod x a /= 0) $ takeWhile (\a -> a * a <= x) [2..x-1]

cube :: Int -> Int
cube x = x * x * x

check :: Int -> Bool
check x = isPrime $ cube (x + 1) - cube x

ans = length $ filter check $ takeWhile (\x -> cube (x + 1) - cube x < 1000000) [1..1000000]
