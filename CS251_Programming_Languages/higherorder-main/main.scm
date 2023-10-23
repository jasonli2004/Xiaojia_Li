;;; This function takes in another function and then create procedure combining the function wit three nested parameters
(define curry3
  (lambda (f) 
    f (lambda (x)
	(lambda (y)
	  (lambda (z)
	    (f x y z))))))

;;; This function takes in a procedure that takes in three parameter and return the result of running the procedure on these 3 parameters
(define uncurry3
  (lambda (prcd)
    (lambda (x y z)
      (((prcd x) y) z))))

;;; This function takes in a function and a list and applies the function on every member of the list as individual parameter
(define helper
  (lambda (f lst)
    (if (null? lst)
	f
	(helper (f (car lst)) (cdr lst)))))

;;; This function takes in a procedure and use the helper function to apply the procedure to the list of arguments
(define uncurry
  (lambda (prcd)
    (lambda args
      (helper prcd args))))

;;; This function takes in a list and a procedure and return a list that contains element of the old list that makes the procedure true
(define my-filter
  (lambda (prcd lst)
    (cond ((null? lst) '())
	  ((prcd (car lst)) (cons (car lst) (my-filter prcd (cdr lst))))
	  (else (my-filter prcd (cdr lst))))))

;;; This function takes in two lists and return the union by filtering the elements of the second list that are not inside the first list and append them to the first list
(define union
  (lambda (lst1 lst2)
    (append lst1 (my-filter (lambda(x)  (equal? #f (member x lst1))) lst2))))

;;; This function takes in two lists and return the intersection by filtering the elements that is in the first list and the second list
(define intersect
  (lambda (lst1 lst2)
    (my-filter (lambda(x) (not (equal? #f (member x lst1)))) lst2)))

;;; This functions takes in a list and a procedure and return if any element in the list pass the procedure by checking filtering out all the unqualified elements return the empty list
(define exists
  (lambda (prcd lst)
   (not (null? (my-filter prcd lst)))))
	

