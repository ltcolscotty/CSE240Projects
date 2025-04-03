(#%require (lib "27.ss" "srfi"))
(random-source-randomize! default-random-source)

(define congratulate
  (lambda (name)
    (display (string-append "Good game, " name "!"))
  ))

(define get_guess
  (lambda (target guesses)
    (display "Enter guess: " )
     (let ((guess (read)))
    (cond
      ((= guess target)
       (display (string-append "Correct! You made " (number->string guesses) " guesses..."))
       (newline)
       (display "Please enter your name: ")
       (let ((name (read)))
         (congratulate (symbol->string name))))
      ((< guess target)
       (display "Higher...")
       (get_guess target (+ guesses 1)))
      ((> guess target)
       (display "Lower...")
       (get_guess target (+ guesses 1)))
       ))))

(define play_guess
  (lambda (target init)
    (display "Guess a number from 1 to 100")
    (newline)
    (get_guess target init)))

(play_guess (+ (random-integer 99) 1) 1)