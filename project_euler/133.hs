primes :: [Integer]
primes = sieve [2..]
	where
		sieve (x:tl) = x : sieve [e | e <- tl, mod e x > 0]
