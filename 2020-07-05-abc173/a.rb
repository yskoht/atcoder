n = gets.to_i

res = 0
loop {
  break if res >= n
  res += 1000
}
puts res - n