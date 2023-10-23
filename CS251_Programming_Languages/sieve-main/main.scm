;;;code created by Lee Li for CS251 assignment on Jan 17 2023
;;;this procedure create a lazy list containing sequence of elements from first to last
(define seq
  (lambda (first last)
    (if (> first last)
	#f
	(cons first (lambda() (seq (+ 1 first) last))))))

;;;this procedure returns a integer lazy list of elements from first to infinity
(define inf-seq
  (lambda (first)
    (cons first (lambda() (inf-seq (+ first 1))))))

;;;this procedure takes in a lazy list and a number and returns a normal scheme list containing
;;;the first n values in the lazy list, returns #f if the lazy list has fewer than n values
(define first-n
  (lambda (lzylst n)
    (if (or (equal? n 0) (equal? #f lzylst))
	'()
	(cons (car lzylst) (first-n ((cdr lzylst)) (- n 1))))))

;;;this procedure takes in a lazy list and a number and returns the nth value in the lazylist, returns false
;;;if the lazy list has fewer than n elements
(define nth
  (lambda (lzylst n)
    (cond
     ((equal? #f lzylst) #f)
     ((equal? 1 n) (car lzylst))
     (else (nth ((cdr lzylst)) (- n 1))))))

;;;this procedure takes in a lazy list and a number and returns a new lazy list with all n and multiples of n removed
(define filter-multiples
  (lambda (lzylst n)
    (cond
     ((equal? lzylst #f) #f)
     ((equal? (modulo (car lzylst) n) 0) (filter-multiples ((cdr lzylst)) n))
     (else (cons (car lzylst)
		 (lambda() (filter-multiples ((cdr lzylst)) n)))))))

;;;this procedure calls the primes-helper function and passes a infinite lazylist of integers starting from 2
;;;this procedure returns a infinite lazy list of prime numbers
(define primes
  (lambda ()
    (primes-helper (inf-seq 2))))

;;;this procedure takes in a lazylist that has been treated using the "Sieve of Eratosthenes" method
;;;this procedure should returns a infinite lazy list of prime numbers with correct input
(define primes-helper
  (lambda(lzylst)
    (cons (car lzylst)
	  (lambda () (primes-helper (filter-multiples ((cdr lzylst)) (car lzylst)))))))
