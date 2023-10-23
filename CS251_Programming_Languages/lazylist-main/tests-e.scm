;; DO NOT CHANGE THESE TESTS.

;; Module to include testing code
(use-modules (srfi srfi-64))

(test-equal "gen-list-single" '(3) (gen-list 3 3))
(test-equal "gen-list-empty" '() (gen-list 5 3))

(define one-lazy-item (gen-lazy-list 3 3))
(test-equal "gen-lazy-list-single" 3 (car one-lazy-item))
(test-assert "gen-lazy-list-single-end-no-error" (not ((cdr one-lazy-item))))

(test-assert "gen-lazy-list-empty-no-error" (not (gen-lazy-list 5 3)))

(test-assert "make-lazy-list-empty-no-error" (not (make-lazy '())))
(test-assert "make-lazy-end-no-error" (not ((cdr ((cdr ((cdr (make-lazy '(3 4 5))))))))))