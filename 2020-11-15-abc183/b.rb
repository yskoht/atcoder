sx, sy, gx, gy = gets.chomp.split.map(&:to_i)

left = [sx, gx].min
right = [sx, gx].max

1000000.times do
  k = (right + left) / 2.0

  lg = Math.sqrt((gx - k) ** 2 + gy ** 2)
  ls = Math.sqrt((sx - k) ** 2 + sy ** 2)

  tg = Math.asin(gy.abs / lg)
  ts = Math.asin(sy.abs / ls)

  if (tg - ts).abs < 1e-9
    puts k
    break
  end

  if sx < gx
    if tg > ts
      right = k
    else
      left = k
    end
  else
    if tg < ts
      right = k
    else
      left = k
    end
  end
end
