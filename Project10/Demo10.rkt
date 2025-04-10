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
;(min-list L1)

(define wow
  (lambda (n)
    (if (= n 1)
        1
        (+ (* 2 n) (wow (- n 1))))))
;(wow 3)

(define (exists? p? xs)
  (if (null? xs)
      #f
      (or (p? (car xs))
          (exists? p? (cdr xs)))))

(exists? number? '(1 b 3))


(define (forall? p? xs)
  (if (null? xs)
      #f
      (and (p? (car xs))
          (forall? p? (cdr xs)))))

;(exists? char-alphabetic? '(1 b 3))

(map (lambda (x) (* 2 x)) '(1 2 3))

(define (mapp f xs)
  (if (null? xs)
      '()
      (cons (f (car xs)) (mapp f (cdr xs)))))

;(mapp (lambda (x) (* 2 x)) '(1 2 3))

(define (filter p? xs)
  (if (null? xs)
      '()
      (if (p? (car xs))
          (cons (car xs) (filter p? (cdr xs)))
          (filter p? (cdr xs)))))

(filter number? '(1 b 3 d e 7))

(define (foldr f z xs)
  (if (null? xs)
      z
      (f (car xs) (foldr f z (cdr xs)))))

(foldr + 0 '(1 2 3 4))

(define (count_letters word)
  (length (filter char-alphabetic? (string->list word))))

(display "Letter count:  ")

(display (count_letters "This is a test."))
(newline)

(define tree '(5 (2 () (3 () ())) (7 (6 () ()) () )))
(display tree)

(define (leftchild B) (cadr B))
(define (rightchild B) (cadr (cdr B)))
(define (data B) (car B))

(newline)
(define (print-tree B)
  (cond ((null? B) '() )
        (else (print-tree (leftchild B))
              (display (data B))
              (display " ")
              (print-tree (rightchild B)))))

(print-tree tree)

(define mydict '((a 1) (b 2) (c 3)))
(assoc 'a mydict)
(cdr (assoc 'a mydict))

(define students
  '((Alice 90)
    (Bob 85)
    (Charlie 92)
    (Diana 88)))

(define (find-grade name)
  (let ((result (assoc name students)))
    (if result
        (cdr result
             "Student not found"))))

(define (something oldlist newlist)
    (if (null? oldlist)
        newlist
        (something (cdr oldlist) (cons (car oldlist) newlist))))

(something '(a b c) '())

(define (listk lst k)
  (cond ((null? lst) ('()))
        ((= k 1) (car lst))
        (else (listk (cdr lst) (- k 1)))))

(listk '(1 2 3 4) 3)