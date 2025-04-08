(define greet
  (lambda (name)
  (display (string-append "Hello " name "!"))))

(greet "Tom")

' (1 2 3)

;(define L '(1 (2 3) ((4) () (5 6))))

(define L1 '(1 2 3 ))
(define L2 '(4 5 6 ))

(define list-sum
  (lambda (L)
    (if (null? L)
        0
        (+ (car L) (list-sum (cdr L))))))

(define (last_element l)
  (cond ((null? (cdr l)) (car l))
        (else (last_element (cdr l)))))

(define reverse2
  (lambda (L)
    (if (null? L)
        '()
        (begin
          (cons (car L))
          (reverse2 (cdr L))))))

(define reverse1
  (lambda (L)
    (if (null? L)
        '()
        (cons (reverse1 (cdr L)) (car L)))))

(define reverse3
  (lambda (L)
    (if (null? L)
        '()
        (append (reverse3 cdr(L))))))