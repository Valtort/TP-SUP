type 'a tree =
Node of 'a * ('a tree list)

(*q16*)
(*Fonction hauteur calculant la hauteur d'un arbre*)
let rec hauteur (Node (x,l) : 'a tree) : int =
  m