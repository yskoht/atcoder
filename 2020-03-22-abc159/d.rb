$memo = Hash.new({})

def choose(n, x)
  return $memo[n][x] if $memo.fetch(n, {}).fetch(x, nil)

  p = 1
  q = 1
  x.times do |i|
    p *= (n - i)
    q *= (i + 1)
  end

  return $memo[n][x] = (p / q).to_i
end

n = gets.to_i
as = gets.chomp.split.map(&:to_i)

h = Hash.new(0)
as.each { |a| h[a] += 1 }
h.select! { |_, v| v >= 2 }

sum = 0
h.each do |k, v|
  sum += choose(v, 2)
end

as.each do |a|
  res = sum
  if h[a]
    res -= choose(h[a], 2)
    res += choose(h[a] - 1, 2) if h[a] - 1 >= 2
  end
  puts res
end
