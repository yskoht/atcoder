n, k, c = gets.chomp.split.map(&:to_i)
s = gets.chomp

def f(str, n, k, c)
  asap = Array.new(n, nil)
  i = 0

  cnt = 0
  while k != 0
    if str[i] == 'o'
      asap[i] = cnt
      k -= 1
      i += c + 1
      cnt += 1
    else
      i += 1
    end
  end

  return asap
end

a = f(s, n, k, c)
b = f(s.reverse, n, k, c).reverse
bmax = b.compact.max
b.map! { |x| x.nil? ? nil : bmax - x }

n.times do |i|
  if a[i] && b[i] && a[i] == b[i]
    puts i + 1
  end
end