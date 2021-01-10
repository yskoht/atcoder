n = gets.to_i

asum = 0
array = []
n.times do
  a, b = gets.chomp.split.map(&:to_i)
  asum += a
  array.push [a, b]
end

arr = array.sort_by{ |x| -(2 * x[0] + x[1]) }

cnt = 0
bsum = 0
arr.each do |a, b|
  cnt += 1
  asum -= 2 * a
  bsum += b
  break if asum < bsum
end

puts cnt
