(define (sort lst key)
  (if (null? lst)
	(list key)
	(if (> key (car lst))
	  (cons (car lst) (sort (cdr lst) key))
	  (cons key lst))))


(define (insertSort new_lst old_lst)
  (if (null? old_lst)
	new_lst
	(insertSort (sort new_lst (car old_lst))
				(cdr old_lst))))

(define lst (list 6 5 4 7 10 2 11))
(define new (list (car lst)))
(define old (cdr lst))

;;testing
;;(insertSort new old)
