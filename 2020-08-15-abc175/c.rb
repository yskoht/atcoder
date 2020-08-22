x, k, d = gets.chomp.split.map(&:to_i)

x = x.abs
t = x / d
a = x - t * d

res =
  if t <= k
    if (k - t) % 2 == 0
      a
    else
      d - a
    end
  else
    (t - k) * d + a
  end

puts res