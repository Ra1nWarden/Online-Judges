primes :: [Integer]
primes = sieve [2..]
	where
		sieve (p:tl) = p : sieve [x | x <- tl, mod x p > 0]

modExpo :: Integer -> Integer -> Integer -> Integer
modExpo a b p
	| b == 1 = mod a p
	| even b = let ans = modExpo a (quot b 2) p in mod (ans * ans) p
	| odd b = let ans = modExpo a (quot b 2) p in mod (ans * ans * a) p

validPrimes = takeWhile (\a -> a < 200000) primes

ans = sum $ take 40 $ filter (\p -> modExpo 10 1000000000 (9*p) == 1) validPrimes
