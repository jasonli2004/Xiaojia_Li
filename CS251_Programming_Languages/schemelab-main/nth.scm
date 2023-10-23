
(define nth
  (lambda (lst n)
    (cond ((null? lst) #f)
	  ((equal? 0 n) (car lst))
	  (else (nth (cdr lst) (- n 1))))))
(define remove
  (lambda (item lst)
    (cond ((null? lst) '())
	  ((equal? item (car lst)) (remove item (cdr lst)))
	  (else (cons (car lst) (remove item (cdr lst)))))))
