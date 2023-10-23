;;;CS251 code by Lee for lazylist lab

;;;generate a list with elements from start to stop, return empty list if start>stop
(define gen-list
  (lambda (start stop)
    (if (> start stop)
	'()
	(cons start (gen-list (+ start 1) stop)))))

;;;returns a boolean about  whether two consecutive elements in the list adds up to target value
(define pair-sum?
  (lambda (lst target)
    (if (< (length lst) 2)
	#f
	(or (equal? (+ (car lst) (car (cdr lst))) target)
	    (pair-sum? (cdr lst) target)))))

;;;another version of gen-list where the first element is the first integer in the sequence, and second one is a procedure that generate the next level.
(define gen-lazy-list
  (lambda (start stop)
    (if (> start stop)
        #f
        (cons start
            (lambda () (gen-lazy-list (+ start 1) stop))))))

;;;the "lazy" version of pair-sum?
(define pair-sum-lazy?
  (lambda (lst target)
    (if (or (equal? #f lst) (equal? #f ((cdr lst))))
        #f
        (or (equal? (+ (car lst) (car((cdr lst)))) target)
            (pair-sum-lazy? ((cdr lst)) target)))))

;;;create a "lazy" version of list by taking a normal scheme list as argument, returns f when reached the end of the list.
(define make-lazy
  (lambda (lst)
    (if (null? lst)
	#f
	(cons (car lst)
	      (lambda() (make-lazy (cdr lst)))))))

(define any-sum-lazy?
  (lambda (lst target)
    (if (or (equal? #f lst) (equal? #f ((cdr lst))))
	#f
	(or (any-sum-help lst target (car lst))
	    (any-sum-lazy? ((cdr lst)) target)))))
(define any-sum-help
  (lambda (lst target current)
    (if (or (equal? #f lst) (equal? #f ((cdr lst))))
        #f
        (or (equal? (+ (car lst) current) target)
	    (any-sum-help ((cdr lst)) target current)))))
