;sum up all the numbers in a list through recursive calls, adding up first two elements in the list every time. Returns 0 when list is empty.
(define sum
  (lambda (x)
    (cond
     ((= (length x) 0) 0)
     ((= (length x) 1) (car x))
     (else
      (sum
       (cons
	(+
	 (car x)
	 (car
	  (cdr x)))
	(cdr
	 (cdr x))))))))
;a recursive function that keep the first n elements of a list and returns a empty list when n > length of the list or n <= 0.
(define keep-first-n
  (lambda (num x)
    (cond
     ((or (or (= num 0) (< num 0)) (> num (length x))) '())
     (else
      (cons
       (car x)
       (keep-first-n
	(- num 1)
	(cdr x)))))))
