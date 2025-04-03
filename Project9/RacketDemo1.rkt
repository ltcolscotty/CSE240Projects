(define sign
  (lambda (x)
    (cond
      ((positive? x)
       1)
      ((zero? x)
       0)
      (else
       -1))))

(define double
  (lambda (x)
    (* x 2)))

(let ((a 2)
      (b 10)
      (c (read)))
  (if (> c (- b 2))
  b
  (+ c 2)))

(#%require racket/trace)

(define triangular
  (lambda (n)
    (if (= n 1)
        1
        (+ n (triangular ( - n 1))))))

(display "Triangular: ")
(define d (read))
(trace triangular)
(triangular d)

(define power
  (lambda (x n)
    (if (zero? n)
    1
    (* x (power x (- n 1))))))

(trace power)
(power 4 9)

