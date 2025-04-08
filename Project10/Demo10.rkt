(#%require racket/trace)
(define factorial1
  (lambda (n)
    (if (= n 1)
    1
    (* n (factorial1 (- n 1))))))

(trace factorial1)

;(factorial1 6)
;(newline)

(#%require racket/trace)

(define factorial2
  (lambda (n result)
    (if (= n 1)
        result
        (factorial2 (- n 1) (* n result)))))

(trace factorial2)

;(factorial2 6 1)

(#%require racket/trace)

(define reverse2
  (lambda (oldlist newlist)
    (if (null? oldlist)
    newlist
    (reverse2 (cdr oldlist) (cons (car oldlist) newlist)))))

(define (reverse2b oldlist newlist)
    (if (null? oldlist)
    newlist
    (reverse2b (cdr oldlist) (cons (car oldlist) newlist))))

(define L '(1 2 3))

(trace reverse2b)
;(reverse2b L '())

(#%require racket/trace)

(define (fib x)
  (if (<= x 1)
      x
      (+ (fib (- x 1)) (fib (- x 2)))))

(trace fib)
;(fib 5)

(#%require racket/trace)

(define (min-list lst)
  (cond
    ((null? lst) (error "Empty list"))
    ((= (length lst) 1) (car lst))
    (else (min (car lst) (min-list (cdr lst))))))

(define L1 '(5 2 6))

(trace min-list)
(min-list L1)

(define wow
  (lambda (n)
    (if (= n 1)
        1
        (+ (* 2 n) (wow (- n 1))))))
(wow 3)