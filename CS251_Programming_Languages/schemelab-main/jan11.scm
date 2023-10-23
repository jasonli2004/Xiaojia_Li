(define subset
  (lambda (old new input)
    (cond ((null? input)    '()   )
	  ((list? input) (cons (subset old new (car input))
			       (subset old new (cdr input))))
	  ((equal? input old) new)
	  (else input))))
(define subsets
  (lambda (x)
    (cond
     ((null? x) '())
     (else
      (cons
       (append '() subsets(cdr x))
     (append (list car
