(define curry3
  (lambda (f)
    (lambda(a)
      (lambda(b)
        (lambda (c)
          (f a b c))))))
(define curry4
  (lambda (f)
    (lambda(a)
      (lambda(b)
        (lambda (c)
          (lambda (d)
          (f a b c d)))))))

(define uncurry3
 (lambda(cuf)
   (lambda (a b c) (((cuf a) b) c))))

(define uncurry-help
  (lambda (f args)
    (if (equal? 1 (length args))
        (f (car args))
        (uncurry-help (f (car args)) (cdr args)))))

(define uncurry
  (lambda (f)
    (lambda args (uncurry-help f args))))

(define my-filter
  (lambda (f lst)
    (cond ((null? lst) '())
          ((f (car lst)) (cons (car lst) (my-filter f (cdr lst))))
          (else (my-filter f (cdr lst))))))

(define union
  (lambda (lst1 lst2)
    (if (null? lst1)
        '()
        (append lst1 (my-filter (lambda(x) (not (member x lst1))) lst2)))))

(define intersect
  (lambda (lst1 lst2)
    (if (null? lst1)
        '()
        (my-filter (lambda(x) (not (equal? #f (member x lst1)))) lst2))))

(define exists
  (lambda (f lst)
    (not (null? (my-filter f lst)))))




