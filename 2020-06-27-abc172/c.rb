n, m, k = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)
b = gets.chomp.split.map(&:to_i)

sum_a = Array.new(n+1)
sum_b = Array.new(m+1)

prev = 0
sum_a[0] = 0
a.each.with_index do |x, i|
  sum_a[i+1] = prev + x
  prev = sum_a[i+1]
end

prev = 0
sum_b[0] = 0
b.each.with_index do |x, i|
  sum_b[i+1] = prev + x
  prev = sum_b[i+1]
end

res = 0
sum_a.each.with_index do |x, i|
  t = k - x
  next if t < 0
  q = sum_b.bsearch_index { |y| y >= t }
  next if q.nil?

  if x + sum_b[q] <= k
    r = i+q
    res = [res, r].max
    next
  end
  if q >= 1 && x + sum_b[q-1] <= k
    r = i+q-1
    res = [res, r].max
    next
  end
end

puts res
