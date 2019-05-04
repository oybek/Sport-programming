
(for { a <- 1L to 1000L
       b <- 1L to 1000L}
    yield (a, b, 1000L-a-b)
).toList.filter {
  case (a, b, c) => a*a + b*b == c*c
}.map {
  case (a, b, c) => a*b*c
}